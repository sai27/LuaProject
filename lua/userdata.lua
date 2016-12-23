local a = BinaryArray.New(1000)
local metatable = getmetatable(a)
metatable.__index = metatable.Get
metatable.__newindex = metatable.Set
metatable.__len = metatable.Count

a[6] = true
print(a[6])
print(#a)