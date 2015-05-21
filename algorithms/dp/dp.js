// let arr[n] be the number of ways to
// climb up n steps. with hops of 1,2,3.
// arr[n] = arr[n-1] + arr[n=2] + arr[n - 3]

function upTheStairs(n) {
  
    var arr = [];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (var i = 4; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
}



// find i such that arr[i] = i 
// assume arr is sorted

function magicSpot(arr) {
	
	var start = 0;
	var end = arr.length - 1;

	while (start <= end) {

		var mid = Math.floor((start + end)/2);

		if (arr[mid] == mid) {
			return mid;
		}

		if (arr[mid] < mid) {
			start = mid + 1;
		}
		else if (arr[mid] > mid) {
			end = mid - 1;
		}

	}
	return -1;
}


function powerSet(s) {

	var len = s.length;

	power = [];
	power[0] = [];

	for (var i = 0; i < len; i++) {
		var len2 = power.length;
		for (var j = 0; j < len2; j++) {
			var temp = [];
			temp.concat(power[j]);
			temp.push(s[i]);
			power.push(temp);
		}
	}

	return power;
}



