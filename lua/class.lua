prototype_base = { balance = 5 }

function prototype_base:deposite(v)
	self.balance = self.balance + v
	print("prototype_base:deposite")
end

function prototype_base:new(o)
	o = o or {}
	self.__index = self
	setmetatable(o,self)
	return o
end

prototype_inherit = prototype_base:new({balance = 10})
function prototype_inherit:deposite(v)
	self.balance = self.balance + v
	print("prototype_inherit:deposite")
end

obj1 = prototype_base:new({})
obj1:deposite(5)

obj2 = prototype_inherit:new({})
obj2:deposite(5)

local v = rawget(obj2,"balance")
print(v)
-- 重要
-- Lua实现面向对象采用的Prototype（原型）的方式，并非C++中Class/Object的方式
-- 原型的中数据也不应该被具体对象破坏，
-- 如果对象中没有某项数据，查询的时候可以根据metatable查询prototype中的内容
-- 但是在赋值的时候是赋值到对象的table当中，之后使用也会使用对象table的数据
-- brilliant design!