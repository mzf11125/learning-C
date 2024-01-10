# FILEPATH: Untitled-3

def decrypt_string(s):
    decryption_table = {'0': 'O', '1': 'I', '3': 'E', '4': 'A', '5': 'S', '6': 'G', '7': 'T', '8': 'B'}
    decrypted_string = ''
    for c in s:
        if c in decryption_table:
            decrypted_string += decryption_table[c]
        else:
            decrypted_string += c
    return decrypted_string

def shift_string(s, k):
    shifted_string = s[k:] + s[:k]
    return shifted_string

# Read input from file
with open('testdata.in', 'r') as file:
    t = int(file.readline().strip())
    for case in range(1, t+1):
        k = int(file.readline().strip())
        encrypted_string = file.readline().strip()
        
        # Decrypt the string
        decrypted_string = decrypt_string(encrypted_string)
        
        # Shift the string
        shifted_string = shift_string(decrypted_string, k)
        
        # Print the output
        print(f"Case #{case}: {shifted_string}")





int main() 