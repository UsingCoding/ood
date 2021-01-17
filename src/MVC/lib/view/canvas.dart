import 'package:flutter/material.dart';

class Canvas extends StatefulWidget
{
  @override
  State createState() => _CanvasState();
}

class _CanvasState extends State<Canvas>
{
  @override
  Widget build(BuildContext context) {
    return Center(
      child: GestureDetector(
        onTap: () {
          print('HI');
        },
        child: ClipPath(
          clipper: CanvasClipper(),
          child: Container(
            width: 600,
            height: 600,
            color: Colors.pink,
          ),
        ),
      ),
    );
  }
}

class CanvasClipper extends CustomClipper<Path> {
  @override
  Path getClip(Size size) {
    Path path = Path()
      ..addOval(Rect.fromPoints(Offset(0, 0), Offset(60, 60)))
      ..addOval(Rect.fromPoints(Offset(40, 40), Offset(160, 160)))
      ..close();

    return path;
  }

  @override
  bool shouldReclip(CustomClipper<Path> oldClipper) {
    return false;
  }
}