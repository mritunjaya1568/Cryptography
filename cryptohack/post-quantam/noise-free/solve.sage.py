

# This file was *autogenerated* from the file solve.sage
from sage.all_cmdline import *   # import sage library

_sage_const_13411 = Integer(13411); _sage_const_64 = Integer(64); _sage_const_257 = Integer(257); _sage_const_0x10001 = Integer(0x10001); _sage_const_0 = Integer(0); _sage_const_97 = Integer(97); _sage_const_1 = Integer(1)
from pwn import *
from Crypto.Util.number import *
import json

def recv_row(r,message):
	req = json.dumps({"option":"encrypt","message":int(message)})
	r.sendline(req)
	dect = eval(r.recvline().decode().strip())
	A = eval(dect['A'])
	b = int(dect['b'])
	return A,b

def recv_flag(r,index):
	req = json.dumps({"option":"get_flag","index":int(index)})
	r.sendline(req)
	dect = eval(r.recvline().decode().strip())
	A = eval(dect['A'])
	b = int(dect['b'])
	return A,b

HOST = 'socket.cryptohack.org'
PORT = _sage_const_13411 

FLAG = b"crypto{????????????????????????}"
flag_len = len(FLAG)

# dimension
n = _sage_const_64 
# plaintext modulus
p = _sage_const_257 
# ciphertext modulus
q = _sage_const_0x10001 

r = remote(HOST, PORT)
print("Connected")
print(r.recvline())

lest = []
out = []
rank = _sage_const_0 

while rank != n:
	A,b = recv_row(r,_sage_const_97 )
	if matrix(GF(q),lest + [A]).rank() > rank:
		lest.append(A)
		out.append(b - _sage_const_97 )
		rank += _sage_const_1 

M = matrix(GF(q),lest)
out = vector(GF(q),out)

if M.det() != _sage_const_0 :
	print("Got S")
	S = M.solve_right(out)
else:
	print("Failed to find S")


flag = ''
for i in range(flag_len):
	A,b = recv_flag(r,i)
	flag_chr = int(b - vector(GF(q),A) * S) % p
	flag += chr(int(flag_chr))

print(flag)

''' crypto{linear_algebra_is_useful} '''

