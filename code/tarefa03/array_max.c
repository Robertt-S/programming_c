#include <stdio.h>

int main() {
  int nums[5];
  int i, j, k, max;
  
  i = 0;
  while (i <= 4) {
    scanf("%d", &nums[i]);
    i++;
  }
  
  for (j = 0; j <= 4; j++) {
    for (k = 0; k <= 4; k++) {
      if (nums[j] >= nums[k]) {
        max = nums[j];
      } else if (nums[k] >= nums[j]) {
        max = nums[k];
        nums[j] = nums[k];
      }
    }
  }
  
  printf("%d\n", max);
  
}