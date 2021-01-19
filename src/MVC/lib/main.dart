import 'package:MVC/view/canvas.dart';
import 'package:MVC/view/menu.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(App());
}

class App extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'MVC',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: Scaffold(
          appBar: AppBar(
            title: Text('MVC'),
          ),
          body: CanvasView(),
          bottomNavigationBar: Menu()
      ),
    );
  }
}