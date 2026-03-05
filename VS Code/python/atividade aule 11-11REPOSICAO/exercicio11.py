import random

participantes = ["Ana", "Bruno", "Carla", "Diego", "Edu"]

print("Ganhador:", random.choice(participantes))
random.shuffle(participantes)
print("Lista embaralhada:", participantes)
