import 'package:MVC/view/shape_view.dart';
import 'package:MVC/view/shapes/rectangle_view.dart';
import 'package:flutter/material.dart';

class CanvasView extends StatefulWidget
{
  @override
  State createState() => _CanvasViewState();
}

class _CanvasViewState extends State<CanvasView>
{
  @override
  Widget build(BuildContext context) {
    final size = MediaQuery.of(context).size;
    print(size);
    return Container(
      width: size.width,
      height: size.height,
      color: Colors.white,
      child: GestureDetector(
        onTapUp: (TapUpDetails details) {
          print(details.localPosition);
          print(details.globalPosition);
        },
        child: CustomPaint(
          size: Size.infinite,
          painter: _CanvasPainter([RectangleView()]),
        ),
      )
    );
  }
}

class _CanvasPainter extends CustomPainter {
  final List<ShapeView> _shapes;

  _CanvasPainter(this._shapes);

  @override
  void paint(Canvas canvas, Size size) {
    _shapes.forEach((ShapeView shape) => shape.draw(canvas, size));
  }

  @override
  bool shouldRepaint(CustomPainter oldDelegate) {
     return false;
  }
}