local File = file.open("msg-1024bytes.txt", "r")
local msg = File.read()
File:close(); File = nil

local counter = 0
local Time_start = tmr.now()
while (counter < 1000) do
    hash = crypto.hash("MD5",msg)
    counter = counter + 1
end
local Time_end = tmr.now()
local Time_hash = (Time_end - Time_start)

File = file.open("result-hash-md5-1024bytes.txt", "a+")
File.writeline("Time Elapsed: "..Time_hash)
File.writeline("Hash: "..crypto.toHex(hash))
File:close(); File = nil

