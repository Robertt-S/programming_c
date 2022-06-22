#include <stdio.h>

int main() {
  int nums[100];
  int min, max, i, j, k;
  
  
  for (i = 0; i <= 100; i++) {
    scanf("%d", &nums[i]);
    if (nums[i] == 0) {
      break;
    }
  }
  
  j = 0;
  k = 0;
  min = 0;
  while (nums[j] != 0) {
    while (nums[k] != 0) {
      if (nums[j] <= (nums[k] && min)) {
        min = nums[j];
      } else if (nums[k] <= nums[j]) {
        min = nums[k];
      }
      k++;
    }
    k = 0;
    j++;
  }
  
  j = 0;
  k = 0;
  max = 0;
  while (nums[j] != 0) {
    while (nums[k] != 0) {
      if (nums[j] >= (nums[k] && max)) {
        max = nums[j];
      } else if (nums[k] >= nums[j]) {
        max = nums[k];
      }
      k++;
    }
    k = 0;
    j++;
  }
  
  printf("min:%d\n", min);
  printf("max:%d\n", max);
  
  return 0;
}
