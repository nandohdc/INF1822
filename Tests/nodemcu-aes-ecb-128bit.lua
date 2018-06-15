--File = file.open("msg-1024bytes.txt", "r")
--msg = File.read(1024)
--File:close(); File = nil

msg = [[9nefGrf0
Lp3vTWRU
hQKIwIe4
pD7TeMOZ
7GxFE44o
zb9wyOR1
GNpkJNGM
L93gyKYm
s27MY8Wn
bM23GqkU
YHMRKGnn
Vm3YLcUI
ZuEWbTGW
lQRpGJM4
b2DGBrMK
1horEuiS
v4v1IUxB
RoE1jWtb
fwLZxcDG
ThV91uTn
bWbBGXsm
BC1FzToI
UtwyG5xw
wLIdg4qe
Qbr03BjG
x5tlfogS
IrvqJhiB
LjkvFEb0
EMltUqVv
KCU5A6fJ
UNjlQI0t
oCYZXWua
mL41fcmn
9oDARzFj
ikkoK4nb
tgXX2b9F
tW6iWyy3
EFuvhRvt
PgG4hPcT
b4kwmKbd
OXnExFDu
kRtGZ8lU
0mKtjYX5
ntShwbOG
lVqRWAT0
QKGDOSxr
zUoGGfKq
dZOAhqdM
ErA2aUwE
aPZ3Pqab
S18KEilE
5BQVwi8y
1PXvfgEm
0i6bm4nI
LSJXA3Rx
jdgK7csV
TGcCbr9N
w6pKfMNd
UH85mImE
3krswKic
XbNy6RX2
23zawRpw
mjsxLubL
w5QNo8aU
SLWBo8cY
0TgZsCkH
1wlSuWyc
g00e1DFy
1eDoKuBl
CKmuu9CZ
0SWarF83
B8MP1L8v
bbNcvt95
aEA9fbP8
yFatVpM0
VR7V95S3
MOCKJk3k
HaNFces8
1n6qFSYD
lV72ccOq
TvyRH7YY
EkTalAHn
xn2rTmZg
dqzvTdDK
opcgmMS4
7cPIH49r
XI91XHA2
88eYRoLC
4MdSbJDW
qJYALjvi
vrydcRhb
uD9aRcF4
bvdGjK3Y
ZLGR06xa
vf7XhG4y
VBX7nIiq
pAkTdQsv
U2vpR1pR
9lLNRPAB
ZIXEx2LR
TJ7yQ3q0
a6se4ugo
j4pylYeV
gkfFKORK
4iog9o3r
1uKZkF38
kHraEMhJ
p56o5qXK
FFox8wWJ
Ktqjuk2D
k3YALRyy
k3tozBXV
JPmJm8Ts
DuB4FBpA
0AVqdXev
zC4jNwXV
zmCg00oq
BB5zLL54
Y0ljYR9N
NXMsinDx
MX5wGsqz
P2LCdlrN
MyEd52Li
FK1Kg5RX
rMOjo2wX
aP4qlsMb
FimRqQOx
R7uWfLJO]]

print(msg)

counter = 0
Time_start = tmr.now()
while (counter < 1000) do
    obj = crypto.encrypt("AES-ECB", "1234567890abcdef",msg)
    counter = counter + 1
end
Time_end = tmr.now()
print(crypto.toHex(obj))
Time_elapsed = (Time_end - Time_start)  
print(Time_elapsed/1000)

File = file.open("result-aes-ecb-1024bytes.txt", "a+")
File.writeline(Time_elapsed)
File:close(); File = nil
