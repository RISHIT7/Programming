var _set = new Set()
_set.add(1).add(3).add(5).add(7) // Used to check the presence of element hence no loops needed like arrays
console.log(_set.size)
console.log(_set.has(3))
console.log(_set.delete)
console.log(_set.values())
for (const entry of _set.values()) {
    console.log(entry)
}
var __set = new Set([1, 1, 3, 4, 5, 7, 3, 45, 6, 2, 5, 7, 0])
console.log(__set.values())
var _set_ = new Set("hello")
console.log(_set_.values())