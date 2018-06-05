File = file.open("msg-16bytes.txt", "r")
msg = File.read()
File:close(); File = nil

print(msg)

counter = 0
Time_start = tmr.now()
while (counter < 1000) do
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef",msgg)
    counter = counter + 1
end
Time_end = tmr.now()
print(crypto.toHex(obj))
Time_elapsed = (Time_end - Time_start)  
print(Time_elapsed/1000)

File = file.open("result-aes-ecb-1024bytes.txt", "a+")
File.writeline(Time_elapsed)
File:close(); File = nil
