import 'package:MVC/common/point.dart';
import 'package:MVC/common/size.dart';

class Rect {
  final Point _leftTop;
  final Size _size;

  Rect(this._leftTop, this._size);

  Point get leftTop => _leftTop;

  Size get size => _size;
}