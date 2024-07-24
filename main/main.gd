extends Node2D

var particulas

func _ready():
	particulas = Particulas.new()
	particulas.explode(Vector2(128, 128), 50)  # Crear 50 partículas
	set_process(true)

func _process(delta):
	particulas.step(1)
	queue_redraw()

func _draw():
	var positions = particulas.get_positions()
	for pos in positions:
		draw_circle(pos, 5, Color(1, 0, 0))  # Dibujar un círculo rojo con radio 5
