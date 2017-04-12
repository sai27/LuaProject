local function send(x)
	coroutine.yield(x)
end

local function recive(co)
	local status, value = coroutine.resume(co)
	return value
end

function producer()
	local co = coroutine.create( 
		function()
			while true do
				local x = io.read()
				send(x)
			end
		end
	)
	return co
end

function filter(origin_co)
	local co = coroutine.create(
		function()
			for line=1,math.huge,1 do
				local v = recive(origin_co)
				v = string.format("%d: %s", line, v)
				send(v)
			end
			
		end
	)
	return co
end

local function customer(co)
	while true do
		local v = recive(co)
		io.write(v,'\n')
	end
end

customer(filter(producer()))