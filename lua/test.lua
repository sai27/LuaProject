function show()  
    local b = {}  
    local index  
      
    for index = 1,10,1 do  
        print(index)  
    end  
end  
  
show()

local b = BinaryArray.New(1000)

BinaryArray.Set(b, 5,true)
print(BinaryArray.Get(b,-5))