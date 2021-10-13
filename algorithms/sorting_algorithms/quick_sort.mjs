const quicksort = (array, start, end) => {
  if (start >= end) {
    return;
  }
  let pivot = Math.floor((end + start) / 2);
  let index = partition(array, start, end, pivot);
  quicksort(array, start, index - 1);
  quicksort(array, index, end);
};

const partition = (array, left, right, pivot) => {
  pivot = array[pivot];
  while (left <= right) {
    while (array[left] < pivot) {
      ++left;
    }
    while (pivot < array[right]) {
      --right;
    }
    if (left <= right) {
      let temp = array[left];
      array[left] = array[right];
      array[right] = temp;
      left++;
      right--;
    }
  }
  return left;
};

let arr = [];
console.time(start)
for (let i = 0; i < 2000; i++) {
  arr[i] = Math.floor(100 * Math.random(1, 1));
}
quicksort(arr, 0, arr.length - 1);
console.log(arr == arr.sort());
