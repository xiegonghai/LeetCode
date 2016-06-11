//= pp.436, realft, 12.3.2 单个实函数的 FFT
    /// <summary>
    /// 单个实函数的快速傅里叶变换
    /// 计算一组 n 个实值数据点的傅里叶变换。用复傅里叶变换的正半频率替换这些数据，
    /// 它存储在数组 data[1..n] 中。复变换的第一个和最后一个分量的实数值分别返回
    /// 单元 data[1] 和 data[2] 中。n 必须是 2 的幂次。这个程序也能计算复数据数组
    /// 的逆变换，只要该数组是实值数据的变换(在这种情况下，其结果必须乘以 1/n)即可。
    /// </summary>
    /// <param name="data">实型数组 data[1..n]。注意，下标从 1 开始</param>
    /// <param name="isInverse">是否逆变换。注意: 逆变换未乘上归一化因子 1/n</param>
    public static void RealFFT(double[] data, bool isInverse)
    {
      int n = data.Length - 1; // n 必须是 2 的整数幂
      if (!isInverse) ComplexFFT(data, isInverse); // 此处是正向变换
      double theta = (isInverse ? -2 : 2) * Math.PI / n; // 递归的初始赋值
      double wtemp = Math.Sin(0.5 * theta);
      double wpr = -2 * wtemp * wtemp;
      double wpi = Math.Sin(theta);
      double wr = 1 + wpr;
      double wi = wpi;
      double c1 = 0.5;
      double c2 = isInverse ? 0.5 : -0.5;
      int n3 = n + 3;
      int n4 = n >> 2;
      for (int i = 2; i <= n4; i++)
      {
        int i1 = i + i - 1, i2 = i1 + 1, i3 = n3 - i2, i4 = i3 + 1;
        double h1r = c1 * (data[i1] + data[i3]); // 两个分离变换是
        double h1i = c1 * (data[i2] - data[i4]); // 从 data 中分离出来
        double h2r = -c2 * (data[i2] + data[i4]);
        double h2i = c2 * (data[i1] - data[i3]);
        data[i1] = h1r + wr * h2r - wi * h2i; // 此处重新组合以形成
        data[i2] = h1i + wr * h2i + wi * h2r; // 原始实型数据的真实变换
        data[i3] = h1r - wr * h2r + wi * h2i;
        data[i4] = -h1i + wr * h2i + wi * h2r;
        wr = (wtemp = wr) * wpr - wi * wpi + wr; // 递归式
        wi = wi * wpr + wtemp * wpi + wi;
      }
      double tmp = data[1];
      if (!isInverse)
      {
        data[1] = tmp + data[2]; // 同时挤压第一个和最后一个数据
        data[2] = tmp - data[2]; // 使它们都在原始数组中
      }
      else
      {
        data[1] = c1 * (tmp + data[2]);
        data[2] = c1 * (tmp - data[2]);
        ComplexFFT(data, isInverse); // 此处是逆变换
      }
    }