from pwn import *
# flag - enc



# for i in range(16):
# 	pti = b'\x00' * i + b'\x01' + b'\x00' * (15-i)
# 	cti = (cti - ct0)
# 	


def spiralRight(matrix):
    right = []
    for j in range(4):
        for i in range(3, -1, -1):
            right.append(matrix[i][j])
    return bytes2matrix(right)


# rotate a 4x4 matrix counterclockwise
def spiralLeft(matrix):
    left = []
    for j in range(3, -1, -1):
        for i in range(4):
            left.append(matrix[i][j])
    return bytes2matrix(left)

# convert bytes to 4x4 matrix
def bytes2matrix(bytes):
    return [list(bytes[i : i + 4]) for i in range(0, len(bytes), 4)]


# convert 4x4 matrix to bytes
def matrix2bytes(matrix):
    return bytes(sum(matrix, []))

SBOX = [184, 79, 76, 49, 237, 28, 54, 183, 106, 24, 192, 7, 43, 111, 175, 44, 46, 199, 182, 115, 83, 227, 61, 230, 6, 57, 165, 137, 58, 14, 94, 217, 66, 120, 53, 142, 29, 150, 103, 75, 186, 39, 31, 196, 18, 207, 244, 16, 213, 243, 114, 251, 96, 4, 138, 197, 10, 176, 157, 91, 238, 155, 254, 71, 86, 37, 130, 12, 52, 162, 220, 56, 88, 188, 27, 208, 25, 51, 172, 141, 168, 253, 85, 193, 90, 35, 95, 105, 200, 127, 247, 21, 93, 67, 13, 235, 84, 190, 225, 119, 189, 81, 250, 117, 231, 50, 179, 22, 223, 26, 228, 132, 139, 166, 210, 23, 64, 108, 212, 201, 99, 218, 160, 240, 129, 224, 233, 242, 159, 47, 126, 125, 146, 229, 0, 252, 161, 98, 30, 63, 239, 164, 36, 80, 151, 245, 38, 107, 3, 65, 73, 204, 8, 205, 82, 78, 173, 112, 219, 136, 123, 149, 118, 32, 215, 163, 74, 134, 248, 68, 110, 45, 59, 145, 178, 156, 100, 177, 221, 2, 92, 20, 40, 144, 101, 140, 169, 116, 143, 202, 1, 113, 209, 104, 133, 128, 70, 89, 216, 147, 122, 131, 9, 249, 121, 109, 191, 77, 124, 246, 55, 198, 187, 185, 17, 60, 180, 203, 19, 158, 97, 206, 148, 5, 87, 170, 236, 222, 194, 15, 214, 241, 211, 234, 42, 41, 153, 62, 102, 152, 69, 181, 34, 48, 226, 11, 195, 154, 174, 167, 135, 232, 72, 171, 33]

def inv_box(lest):
    out1 = []
    out2 = []
    out = []
    for i,j in enumerate(lest):
        out1.append(i)
        out2.append(j)
    for val in sorted(zip(out2,out1),key = lambda x: x[0]):
        out.append(val[1])
    return out

INV_SBOX = inv_box(SBOX)


def sub_key(matrix,key):
    for i in range(4):
        for j in range(4):
            matrix[i][j] = (matrix[i][j] - key[i][j]) % 255


def decrypt_block(ct,key0,key1):