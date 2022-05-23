require_relative 'vec2.rb'
require 'ext'

module Window
  def self.create(size = [640, 480], title = 'Tinny2d', antialiasing = 0, style = 'default')
    Ext::Window.config(antialiasing, style)
    Ext::Window.init(*size, title)
  end

  def self.available?
    Ext::Window.is_available?
  end

  def self.title=(str)
    Ext::Window.set_title str
  end

  def self.title
    Ext::Window.get_title
  end

  def self.dt
    Ext::Window.delta_time
  end

  def self.reset_time!
    Ext::Window.reset_time!
  end

  def self.size
    Ext::Window.get_size
  end
  
  def self.position
    Ext::Window.get_position 
  end
  
  def self.position=(position)
    Ext::Window.set_position position
  end

  def self.running?
    Ext::Window.is_running?
  end

  def self.close
    Ext::Window.close
  end

  def self.destroy!
    Ext::Window.destroy
  end

  def self.frame_rate=(limit)
    Ext::Window.set_frame_rate limit.to_i
  end

  def self.clear
    Ext::Window.clear
  end

  def self.update
    Ext::Window.update
  end

  module View
    def self.position=(position)
      Ext::Window::View.set_position *(position.to_a)
    end

    def self.position
      Ext::Window::View.get_position
    end

    def self.size=(size)
      Ext::Window::View.set_size *(size.to_a)
    end

    def self.size
      Ext::Window::View.get_size
    end

    def self.angle=(angle)
      Ext::Window::View.set_angle angle
    end

    def self.angle
      Ext::Window::View.get_angle
    end

    def self.origin=(position)
      Ext::Window::View.set_origin *(position.to_a)
    end

    def self.origin
      Ext::Window::View.get_origin
    end
  end
end

module Event
  def self.poll?
    Ext::Event.poll?
  end

  def self.wait?
    Ext::Event.wait?
  end

  def self.name
    Ext::Event.name
  end
end

module Draw
  class Image < Ext::Draw::Image
    
  end

  class Font < Ext::Draw::Font

  end

  def self.print(font, str)
    Ext::Draw.print font, str
  end

  def self.texture(quad, texture)
    raise 'Invalid argument' if quad.length != 4

    Ext::Draw.texture(quad.to_a, texture)
  end
  
  def self.circle(radius)
    Ext::Draw.circle radius
  end

  def self.color=(color)
    case color.length
    when 3
      Ext::Draw.color(*(color.to_a), 255)
    when 4
      Ext::Draw.color(*(color.to_a))
    else
      raise 'Invalid argument'
    end
  end

  def self.position=(position)
    Ext::Draw.position *(position.to_a)
  end

  def self.origin=(origin)
    Ext::Draw.origin *(origin.to_a)
  end

  def self.scale=(scale)
    Ext::Draw.scale *(scale.to_a)
  end

  def self.angle=(angle)
    Ext::Draw.angle angle.to_f
  end
end

module Keyboard
  def self.down?(key)
    Ext::Keyboard.is_key_down? key
  end
end

module Mouse
end