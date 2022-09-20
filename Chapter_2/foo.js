async function foo() {
  return true;
}

let x = foo();
x.then(val => console.log(val));
console.log("hello world");