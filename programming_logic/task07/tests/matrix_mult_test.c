#include<stdio.h>
int main() {
  int a[10][10],
  b[10][10],
  c[10][10],
  n,
  i,
  j,
  k;

  printf("Enter the value of N (N <= 10): ");
  scanf("%d", &n);
  printf("Enter the elements of Matrix-A: \n");

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Enter the elements of Matrix-B: \n");

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
  }

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      c[i][j] = 0;
      for(k = 0; k < n; k++) {
        c[i][j] += a[i][k]*b[k][j];
      }
    }
  }

  printf("The product of the two matrices is: \n");
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      printf("%d\t", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}



#include<stdio.h>
int main() {
  int m,
  n,
  p,
  q,
  i,
  j,
  k;
  int a[10][10],
  b[10][10],
  res[10][10];

  printf("Enter the order of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter the order of second matrix\n");
  scanf("%d%d", &p, &q);

  if(n != p) {
    printf("Matrix is incompatible for multiplication\n");
  }
  else {
    printf("Enter the elements of Matrix-A:\n");
    for(i = 0; i < m; i++) {
      for(j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }

    printf("Enter the elements of Matrix-B:\n");
    for(i = 0; i < p; i++) {
      for(j = 0; j < q; j++) {
        scanf("%d", &b[i][j]);
      }
    }

    for(i = 0; i < m; i++) {
      for(j = 0; j < q; j++) {
        res[i][j] = 0;
        for(k = 0; k < p; k++) {
          res[i][j] += a[i][k]*b[k][j];
        }
      }
    }

    printf("The product of the two matrices is:-\n");

    for(i = 0; i < m; i++) {
      for(j = 0; j < q; j++) {
        printf("%d\t", res[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}