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
-- ��Ҫ
-- Luaʵ�����������õ�Prototype��ԭ�ͣ��ķ�ʽ������C++��Class/Object�ķ�ʽ
-- ԭ�͵�������Ҳ��Ӧ�ñ���������ƻ���
-- ���������û��ĳ�����ݣ���ѯ��ʱ����Ը���metatable��ѯprototype�е�����
-- �����ڸ�ֵ��ʱ���Ǹ�ֵ�������table���У�֮��ʹ��Ҳ��ʹ�ö���table������
-- brilliant design!