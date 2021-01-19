import 'package:MVC/domain/shape.dart';

class Canvas
{
  final List<Shape> _shapes = [];

  int get shapesCount => _shapes.length;

  Shape getShapeByIndex(int index)
  {
    if (index >= _shapes.length) {
      throw Exception('Cant get shape more than length');
    }

    return _shapes[index];
  }

  void insertShape(Shape shape) {
    _shapes.add(shape);
  }

  Shape deleteShape(int index) {
    if (index >= _shapes.length) {
      throw Exception('Cant delete shape more than length');
    }

    return _shapes.removeAt(index);
  }
}