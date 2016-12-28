local a = 10

function factory()
	local f = function()
		return a
	end
	return f
end

local f1 = factory()
local f2 = factory()

print(f1())
print(f2())

setfenv(f1,{a = 5})

print(f1())
print(f2())


-- metatable
local a = {
	name = "aaa"
}

local b = {
	__index = function(t,k)
		return a[k]
	end,
--	name = "bbb"
}
local c = {
	__index = function(t,k)
		return b[k]
	end,
--	name = "ccc"
}

setmetatable(b,b)
setmetatable(c,c)
print(c.name)
--[[
local r, err = loadfile("../../lua/module.lua")
if err ~= nil then print(err) return end
local _M = {}
setmetatable(_M, {__index = _G})

setfenv(r, _M)

r()
]]