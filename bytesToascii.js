const bytes = [77,33,101,120,111]

function bytesToascii(bytes) {
  const arr = [];
  for(i=0;i<bytes.length;i++){
    arr.push(String.fromCharCode(bytes[i]));
  }
  return arr;
}

const result = bytesToascii(bytes);
console.log(result);
