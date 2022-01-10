function factors(n) {
	var retString = "";
    var i;
	for (i = 1; i <= n; i++) {
  	if (i == n) {
    	retString += i;
        return retString;
    } else if (n % i == 0) {
		retString += i + ", ";
    }
  }
}