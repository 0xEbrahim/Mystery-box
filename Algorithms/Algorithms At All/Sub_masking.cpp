// submasking is a way to get all subset from the current mask
for(int sub_mask = mask ; sub_mask ; sub_mask = (sub_mask - 1) & mask){
  
}
/*
EXAMPLE:
Mask: 1001101
submasks could be: 1001001 - 1000000 - 1001000 - 0000001
initially, sub_mask will be 1001101 then we reduce the right most 1 so it will be 1001100, then we make AND operation with the original mask to make sure there is not any additional ones
*/
