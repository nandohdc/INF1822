local File = file.open("msg-1024bytes.txt", "r")
local msg = File.read()
File:close(); File = nil

local counter = 0
local Time_start = tmr.now()
while (counter < 500) do
    ciphertext = crypto.encrypt("AES-CBC", "1234567890abcdef", msg)
    counter = counter + 1
end
local Time_end = tmr.now()
local Time_encript = (Time_end - Time_start)

counter = 0
Time_start = tmr.now()
while (counter < 500) do
    text = crypto.decrypt("AES-CBC", "1234567890abcdef", ciphertext)
    counter = counter + 1
end
Time_end = tmr.now()
local Time_decript= (Time_end - Time_start)

File = file.open("result-aes-cbc-8bytes.txt", "a+")
File.writeline("Encript: "..Time_encript)
File.writeline("Ciphertext: "..crypto.toHex(ciphertext))
File.writeline("Decript: "..Time_decript)
File.writeline("Original Msg: "..text)
File:close(); File = nil

