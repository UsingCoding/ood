import 'package:flutter/material.dart';

class Menu extends StatelessWidget
{
  @override
  Widget build(BuildContext context) {
    return BottomAppBar(
      color: Colors.blue,
      elevation: 20,
      child: Row(
        children: [
          _getButton('Rectangle', () { }),
          _getButton('Triangle', () { }),
          _getButton('Ellipse', () { }),
          _getButton('Delete', () { })
        ],
      ),
    );
  }

  Widget _getButton(String text, void Function() callback)
  {
    return FlatButton(
        onPressed: callback,
        child: Text(
          text,
          style: TextStyle(color: Colors.white),
        )
    );
  }
}