const http = require('http')
const url = require('url')

const __calcFibTCO = (n, x, y) => {
  if (n == 0)
    return x
  if (n == 1)
    return y
  return __calcFibTCO(n - 1, y, x + y)
}

const __calcFibRecursion = (n) => {
  if (n <= 1)
    return n
  return __calcFibRecursion(n - 1) + __calcFibRecursion(n - 2)
}

const calcFibonacci = (n) => {
  return __calcFibRecursion(n)
}

let app = http.createServer((req, res) => {
  const { num } = url.parse(req.url, true).query
  res.writeHead(200, { 'Content-Type': 'text/plain' })
  const result = calcFibonacci(num ? +num : '')
  res.end(result + '');
});

app.listen(8080, '127.0.0.1')
console.log('Server is now listening at port 8080: ')
