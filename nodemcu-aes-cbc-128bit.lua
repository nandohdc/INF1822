File = file.open("msg-16bytes.txt", "r")
msg = File.read()
File:close(); File = nil

counter = 0
Time_start = tmr.now()
while (counter < 1000) do
    obj = crypto.encrypt("AES-CBC", "1234567890abcdef", msg16)
    counter = counter + 1
end
Time_end = tmr.now()
print(crypto.toHex(obj))
Time_elapsed = (Time_end - Time_start)  
print(Time_elapsed/1000)

File = file.open("result-aes-cbc-128-16bytes.txt", "a+")
File.writeline(Time_elapsed)
File:close(); File = nil
