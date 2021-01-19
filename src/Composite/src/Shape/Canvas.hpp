#pragma once
#include "../Canvas/ICanvas.hpp"

class Canvas : public ICanvas
{
public:

    Canvas(std::ostream &output);

    void SetLineColor(RGBAColor color) override;
	void SetFillColor(RGBAColor color) override;
	void SetLineThickness(double thickness) override;

	void DrawLine(PointD const& from, PointD const& to) override;
	void FillPolygon(std::vector<PointD> const& vertexes) override;

	void DrawEllipse(double left, double top, double width, double height) override;
	void FillEllipse(double left, double top, double width, double height) override;

private:
    std::ostream & m_output;

	RGBAColor m_lineColor = 0x000000;
    RGBAColor m_fillColor = 0x000000;
	float m_lineThickness = 0.;
};
