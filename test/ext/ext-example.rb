require 'tinny2d'


def randomcolor(n = 255)
  Array.new(3) { rand n }
end

class Circle
  attr_accessor :speed, :position, :radius, :color, :origin

  def initialize
    @speed = Vector2.sample(-50..50, -50..50)
    @position = Vector2.sample(640, 480)
    @radius = (rand(1..7)).to_f
    @color = randomcolor
    @origin = [@radius, @radius]
  end
end

Window.create [640, 480], 'Hello world!', 8
Window.frame_rate = 60
angle = 0
current = 0
last_time = 0
background = randomcolor
circles = Array.new(5000) { Circle.new }


while Window.running?
  while Event.poll?
    name = Event.name
    Window.close if name == 'closed'
  end

  if current > 30
    background = randomcolor
    current = 0
  end

  if Keyboard.down? 'q'
    angle -= 5
  elsif Keyboard.down? 'e'
    angle += 5
  end

  current += 1

  Window.title = "Size: #{Window.size}, FPS: #{1.0 / (last_time - Window.dt)}"

  Draw.color = background

  Window.clear

  Window::View.angle = angle

  circles.each do |c|
    c.position.x = c.position.x % (640 * 4)
    c.position.y = c.position.y % (480 * 4)

    c.position += c.speed * [Window.dt, Window.dt]

    Draw.color = c.color
    Draw.position = c.position.to_a
    Draw.origin = c.origin.to_a
    Draw.circle c.radius
  end

  last_time = Window.dt
  Window.update
  Window.reset_time!
end

Window.destroy!