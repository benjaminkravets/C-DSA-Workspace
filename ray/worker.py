import socket

# Create a TCP socket
worker = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to the server
worker.connect(("localhost", 8080))

# Send the request to the server
request = "reverse"
worker.sendall(request.encode())

# Receive the result from the server
result = worker.recv(1024)

# Decode the result
result = result.decode()

# Print the result
print(result)

# Close the connection
worker.close()
