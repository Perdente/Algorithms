# Matrix
### Rotation of matrix
```c++
//inplace rotation of 90 degree anticlockwise
//https://atcoder.jp/contests/abc218/submissions/25796102
  auto rotate_matrix=[&](VV &a){
    for(int i=0;i<n/2;++i){
      for(int j=i;j<n-i-1;++j){
        temp=a[i][j];
         // Move values from right to top
            a[i][j] = a[j][n-i-1];

            // Move values from bottom to right
            a[j][n-i-1] = a[n-i-1][n-j-1];

            // Move values from left to bottom
            a[n-i-1][n-j-1]= a[n-j-1][i];

            // Assign temp to left
            a[n-j-1][i] = temp;
      }
    }
  };
```
