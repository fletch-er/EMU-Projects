
// #1, Find factors of positive integer
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

// #2, Compute tax according to tax rules
function tax(income, maritalStatus) {
  var taxRate = -1;
  if (!(maritalStatus.toLowerCase().includes("single") || maritalStatus.toLowerCase().includes("married")))
    return "Marital Status must be single or married"
  if (maritalStatus.toLowerCase() === "single") {
    if (income < 30000)
      taxRate = .20;
    else 
      taxRate = 0.25;
  } else {
    if (income < 50000)
      taxRate = .10;
    else 
      taxRate = 0.15;
  }

  if (taxRate == -1)
    return "Something went wrong! Income value probably invalid.";
  return taxRate;
}

// #3 Compute Standard Deviation
function stdDev(nums) {
  // calculate average
  var avg = 0;
  var count = 0;
  for (var digit of nums) {
    avg += digit;
    count++;
  }
  avg = avg/count;
  var retArr = [];
  for (var int of nums)
    retArr.push(Math.pow((int - avg), 2))
  var numerator = 0;
  var denomenator = 0;
  for (var runningSum of retArr) {
    numerator += runningSum;
    denomenator++;
  }
  return (Math.sqrt(numerator / denomenator));
}

// #4 creates ID and password
function createIdPassword(first, last) {
  var id = first.substring(0,1) + last;
  var pwd = first.substring(0,1) + first.substring(first.length - 1, first.length) + last.substring(0, 3) + first.length + last.length;
  return (id.toUpperCase() + " " + pwd.toUpperCase()).split(" ");
}

// #5 remove duplicates
function removeDuplicates(inputArr) {
  var ret = [];
  for (var string of inputArr) {
    if (ret.indexOf(string) == -1) {
      ret.push(string);
    }
  }
  return ret;
}

// #6 Student class
class Student
{
  constructor(name, gpa) {
    this.name = name;
    this.gpa = gpa;
  }

  getName() {
    return this.name;
  }

  getGpa() {
    return this.gpa;
  }

  setName(name) {
    this.name = name;
  }

  setGpa(gpa) {
    this.gpa = gpa;
  }

  isHonors() {
    if (this.gpa > 3)
      return true;
    else 
      return false;
  }
}

// #1 Test, should return "1, 2, 5, 10"
console.log(factors(10));
// #2 Test, should return 0.25
console.log(tax(39000, "single"));
// #3 Test, should return sqrt(2)
var arr = [1, 2, 3, 4, 5];
console.log(stdDev(arr));
// #4 Test, should return JMAXWELL JNMAX47
console.log(createIdPassword("John", "Maxwell"));
// #5 Test, should return [tree, cat, box, dog]
console.log(removeDuplicates(["tree","cat", "box", "cat", "dog", "tree","tree"]));