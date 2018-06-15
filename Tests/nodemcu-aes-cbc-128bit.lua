local File = file.open("msg-16bytes.txt", "r")
local msg = File.read()
File:close(); File = nil

local counter = 0
local Time_start = tmr.now()
while (counter < 1000) do
    obj = crypto.encrypt("AES-CBC", "1234567890abcdef", msg)
    counter = counter + 1
end
local Time_end = tmr.now()
print(crypto.toHex(obj))
local Time_elapsed = (Time_end - Time_start)  
print(Time_elapsed/1000)

File = file.open("result-aes-cbc-128-16bytes.txt", "a+")
File.writeline(Time_elapsed)
File:close(); File = nil
