import 'package:flutter/material.dart';

class RectangleView extends CustomPainter
{
  @override
  void paint(Canvas canvas, Size size) {
    Paint paint = Paint();
    paint.color = Colors.red;

    canvas.drawRect(Rect.fromCenter(
        center: Offset(0, 0),
        height: 40,
        width: 40
    ),
        paint
    );
  }

  @override
  bool shouldRepaint(CustomPainter oldDelegate) {
    return false;
  }
}