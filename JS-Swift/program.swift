// #7 A
func isPrime(n: Int) -> Bool {
  if (n <= 1) {
    return false
  }
  if (n <= 3) {
    return true
  }

  var i = 2
  while (i * i <= n) {
    if ((n % i) == 0) {
      return false
    }
    i = i+1
  }
  return true
}

// #7 B
func displayprimes(n: Int) {
  var l: [Int] = []
  var m = 0
  for k in 1...n {
    if (isPrime(n: k)) {
      l.insert(k, at: m)
      m += 1
    }
  }
  for n in l {
    print(n, terminator: " ")
  }
}

// #8
func tax(i: Int, s: String) -> Int {
  var taxRate: Double
  let sT = s.lowercased()
  if (!(sT == "single" || sT == "married")) {
    return -1
  }
  if (sT == "single") {
    if (i < 30000) {
      taxRate = 0.20;
    }
    else {
      taxRate = 0.25;
    }
  } else {
    if (i < 50000) {
      taxRate = 0.10;
    }
    else {
      taxRate = 0.15;
    }
  }
  return Int(Double(i) * (1 - taxRate));
}

// #9
func quadratic(a: Int, b: Int, c: Int) -> (first: Int, second: Int) {
  var first = 0
  var second = 0
  if (a == 0) {
    return (first, second)
  }
  let delta = (b * b) - (4 * a * c)
  if delta >= 0 {
    first = ( -b + Int(Double(delta).squareRoot())) / 2*a
    second = ( -b - Int(Double(delta).squareRoot())) / 2*a
  }
  return (first, second)
}

// #10
func createIdPassword(f: String, l: String) -> (id: String, pwd: String) {
    var id = String(charAt(s: f, i: 0)) + l
    var pwd = String(charAt(s: f, i: 0)) + String(charAt(s: f, i: f.count-1)) + subString(s: l, start: 0, end: 2) + String(f.count) + String(l.count)
    id = id.uppercased()
    pwd = pwd.uppercased()
    return (id, pwd)
}

func charAt(s: String, i: Int) -> Character {
    return (Array(s))[i]
}

func subString(s: String, start: Int, end: Int) -> String {
  var ret: [Character] = []
  var count = 0
  for k in start...end {
    ret.insert(charAt(s: s, i: k), at: count)
    count += 1
  }
  return String(ret)
}

// #11
func factorial(num: Int) -> Int {
    if num == 1 {
        return 1
    } else {
        return num * factorial(num: num - 1)
    }
}

// #12 
func selectionSort(_ array: [Int]) -> [Int] {
    var arr = array                    
// Outer loop for all elements
    for x in 0 ..< arr.count - 1 {  
        var low = x
    // inner loop for all x+1 elements
        for y in x + 1 ..< arr.count {
        // find the lowest
            if arr[y] < arr[low] {
                low = y
            }
        }
        // make the swap if needed AKA put lowest into the right place
        if x != low {
            let temp = arr[x]
            arr[x] = arr[low]
            arr[low] = temp
        }
    }
    return arr
}