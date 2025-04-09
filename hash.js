
const crypto = require('crypto');

function findPrefix() {
  let input = 0;

  while (true) {
    const text = '100xdev' + input.toString();
    const hash = crypto.createHash('sha256').update(text).digest('hex');

    if (hash.startsWith('0000')) {
      return { input, hash };  // Return input and hash when found
    }

    input++;  // Increment input and continue searching
  }
}

const result = findPrefix();
console.log(`Found hash: ${result.hash} for input: ${result.input}`);

