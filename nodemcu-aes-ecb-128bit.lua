counter = 0
obj = nil
Tstart = tmr.now()
while (counter < 10) do
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef", "Hi, I'm secret!")
    counter = counter + 1
end
Tend = tmr.now()
print(crypto.toHex(obj))
Tfinal = (Tend - Tstart)
print(Tfinal)