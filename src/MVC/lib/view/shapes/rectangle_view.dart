import 'package:MVC/view/shape_view.dart';
import 'package:flutter/material.dart';

class RectangleView implements ShapeView
{
  @override
  draw(Canvas canvas, Size size) {
    {
      Paint paint = Paint();
      paint.color = Colors.black;

      canvas.drawRect(
          Rect.fromCenter(center: Offset(100, 100), height: 100, width: 100),
          paint);
    }

    {
      Paint paint = Paint();
      paint.color = Colors.red;

      canvas.drawRect(
          Rect.fromCenter(center: Offset(200, 100), height: 100, width: 100),
          paint);
    }
  }
}