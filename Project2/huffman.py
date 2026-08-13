import heapq
from collections import Counter


class Node:

    def __init__(self, char=None, freq=0):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq


def build_frequency(text):

    frequency = Counter(text)

    return frequency


def build_huffman_tree(frequency):

    heap = []

    for char, freq in frequency.items():

        node = Node(char, freq)

        heapq.heappush(heap, node)

    while len(heap) > 1:

        left = heapq.heappop(heap)
        right = heapq.heappop(heap)

        new_node = Node(None, left.freq + right.freq)

        new_node.left = left
        new_node.right = right

        heapq.heappush(heap, new_node)

    return heap[0]


def generate_codes(root, code="", codes=None):

    if codes is None:
        codes = {}

    if root is None:
        return codes

    if root.char is not None:
        codes[root.char] = code
        return codes

    generate_codes(root.left, code + "0", codes)
    generate_codes(root.right, code + "1", codes)

    return codes


def compress_text(text, codes):

    compressed = ""

    for char in text:
        compressed += codes[char]

    return compressed


def save_compressed(compressed, codes, output_file):

    with open(output_file, "w") as file:

        file.write(str(codes))
        file.write("\n")
        file.write(compressed)


def decompress_text(compressed, root):

    text = ""
    current = root

    for bit in compressed:

        if bit == "0":
            current = current.left

        else:
            current = current.right

        if current.char is not None:

            text += current.char
            current = root

    return text


def main():

    import os
    folder = os.path.dirname(os.path.abspath(__file__))

    input_file = os.path.join(folder, "input.txt")
    output_file = os.path.join(folder, "compressed.txt")

    try:
        with open(input_file, "r") as file:
            text = file.read()

    except FileNotFoundError:
        print("Error: input.txt was not found.")
        print("Python is looking for the file at:")
        print(input_file)
        return

    if text == "":
        print("File is empty.")
        return

    frequency = build_frequency(text)

    print("Character Frequencies:")

    for char, freq in frequency.items():

        if char == "\n":
            print("\\n :", freq)

        elif char == " ":
            print("SPACE :", freq)

        else:
            print(char, ":", freq)

    
    root = build_huffman_tree(frequency)

    codes = generate_codes(root)

    print("\nHuffman Codes:")

    for char, code in codes.items():

        if char == "\n":
            print("\\n :", code)

        elif char == " ":
            print("SPACE :", code)

        else:
            print(char, ":", code)

    compressed = compress_text(text, codes)

    print("\nOriginal text:")
    print(text)

    print("Compressed binary data:")
    print(compressed)

    save_compressed(compressed, codes, output_file)

    original_size = len(text) * 8
    compressed_size = len(compressed)

    print("\nOriginal size:", original_size, "bits")
    print("Compressed size:", compressed_size, "bits")

    if original_size > 0:

        compression_ratio = (compressed_size / original_size) * 100

        print("Compression ratio:",
              round(compression_ratio, 2), "%")

    print("\nCompressed file saved as:")
    print(output_file)

    decompressed = decompress_text(compressed, root)

    print("\nDecompressed text:")
    print(decompressed)


if __name__ == "__main__":
    main()