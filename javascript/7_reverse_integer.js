// 7 Reverse Integer
// https://leetcode.com/problemset/algorithms/
//
// Reverse digits of an integer.
//
// Example1: x = 123, return 321
// Example2: x = -123, return -321

/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var y = 0;
    while (x !== 0) {
        y = y * 10 + x % 10;
        x = parseInt(x / 10);
        if (y >= 2147483647 || y <= -2147483648) {
            return 0;
        }
    }

    return y;
};

var test = function() {
    console.log(reverse(1534236469));
    console.log(reverse(-123));
    console.log(reverse(0));
};

test();

