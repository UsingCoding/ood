import 'package:MVC/common/rect.dart';

enum ShapeType {
 RECTANGLE,
 TRIANGLE,
 ELLIPSE
}

class Shape {
  final String _id;
  final ShapeType _type;
  Rect _frame;

  Shape(this._id, this._type);

  Rect get frame => _frame;

  ShapeType get type => _type;

  String get id => _id;

  set frame(Rect value) {
    _frame = value;
  }
}