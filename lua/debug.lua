function traceback()
	for level=1, math.huge, 1 do
		local info = debug.getinfo(level, "Sl")
		if not info then break end
		if info.what == "C" then
			print(level,"CFunction")
		else
			print(string.format("[%s]:%d", info.short_src, info.currentline))
		end
	end
end

function getfuncvalue(name)
	local value, found

	for i=1,math.huge,1 do
		local n, v = debug.getlocal(2, i)
		if not n then break end
		if n == name then
			return "local:"..v
		end
	end

	local func = debug.getinfo(2,"f").func
	for i=1,math.huge,1 do
		local n, v = debug.getupvalue(func,i)
		if not n then break end
		if n == name then
			return "upvalue:"..v
		end
	end

	return "env:"..getfenv(func)[name]
end

function foo(a, b)
	local x
	do
		local c = a + b
	end
	local a = 1
	while true do
		local name, value = debug.getlocal(1,a)
		if not name then break end
		print(name, value)
		a = a + 1
	end
end

--foo(10, 20)

local a = "aaa"
function test()
	local a = "bbb"
	local f = function()
		for i=1,100,1 do
			local a = "ccc"
		--	print(a)
		--	traceback()
			local r = getfuncvalue("a")
		--	print(r)
		end
	end
	return f
end

--local f = test()
--f()

-- Profiler
local Counters = {}
local Names = {}
local function hook()
	local f = debug.getinfo(2,"f").func
	if Counters[f] == nil then
		Counters[f] = 1;
		Names[f] = debug.getinfo(2,"Sn")
	else
		Counters[f] = Counters[f] + 1
	end
end

local function getname(func)
	local n = Names[func]
	if n.what == "C" then
		return "1"..n.name
	end
	local lc = string.format("2[%s]:%s", n.short_src, n.linedefined)
	if n.namewhat ~= "" then
		return string.format("3%s (%s)",lc, n.name)
	else
		return lc
	end
end

debug.sethook(hook,"c")
--print(1,2,3)
local f = test()
f()
debug.sethook()

for k,v in pairs(Counters) do
	print(getname(k), v)
end

print("end")