-- generic for
local s = { "a", "b", "c", [5] = "e" }

-- closure
function values(t)
	local i = 0
	return function ()
		i = i+1
		if t[i] ~= nil then
			return i, t[i]
		else
			return nil
		end
	end
end

for i,v in values(s) do
--	print(i)
--	print(v)
end

-- mpairs
function iter(t,i)
	i = i+1
	if (t[i] ~= nil) then
		return i, t[i]
	end
end

function mpairs(t)
	return iter, t, 0
end

for i,v in mpairs(s) do
	print(i..":"..v)
end

-- mpairs1
function mpairs1(t)
	return next, t, nil
end

for i,v in mpairs1(s) do
	print(i..":"..v)
end

function init()
	function define()
	--	error("invalid input")
		print(traceback())
		print(debug.traceback())
	end
end
init()
define()

