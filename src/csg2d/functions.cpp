#include "functions.h"
#include "shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ComplexShape.h"
// #include "circle.h"
// #include "rectangle.h"
// #include "complexshape.h"

sf::Vector2f rotate(const sf::Vector2f &v, double angle_rad)
{
	const float cs = std::cos(angle_rad);
	const float sn = std::sin(angle_rad);

	return { v.x*cs - v.y*sn, v.x*sn + v.y*cs };
}

void updateTexture(sf::Texture &t, const CSG2D::Shape &s, const sf::Color &foreground_color, const sf::Color &background_color)
{
	const auto tex_size = t.getSize();
	std::vector<sf::Uint8> tex_data(tex_size.x*tex_size.y*4u, 0u);
	const sf::Vector2f center = sf::Vector2f(tex_size)/2.f - sf::Vector2f(0.5f, 0.5f);
    for(std::size_t py = 0u; py < tex_size.y; ++py)
    {
	    for(std::size_t px = 0u; px < tex_size.x; ++px)
	    {
	        auto pos = sf::Vector2f(px, py) - center;
	        pos.y = -pos.y;
	        
	        const auto color = s.isIn(pos) ? sf::Color::White : sf::Color::Blue; //foreground_color : background_color;

	        const std::size_t pi = py*tex_size.x + px;
	        const auto i = pi*4u;
	        tex_data[i] = color.r;
	        tex_data[i + 1u] = color.g;
	        tex_data[i + 2u] = color.b;
	        tex_data[i + 3u] = color.a;
	    }
    }
    t.update(tex_data.data());
}

// funckja zwracajaca ksztalt litery C (uzywana w createCSG2DScene)
std::shared_ptr<CSG2D::Shape> createCSG2DCShape()
{
    auto circle_i = std::make_shared<CSG2D::Circle>(25.f, sf::Vector2f());
    auto circle_o = std::make_shared<CSG2D::Circle>(50.f, sf::Vector2f());
    auto letter_o = std::make_shared<CSG2D::ComplexShape>(circle_o, circle_i, CSG2D::OPERATION::DIFFERENCE);

    auto ru = std::make_shared<CSG2D::Rectangle>(100.f, 100.f, rotate(sf::Vector2f(0.f, 50.f), std::numbers::pi/6.f), std::numbers::pi/6.f);
    auto ou = std::make_shared<CSG2D::ComplexShape>(letter_o, ru, CSG2D::OPERATION::INTERSECTION);

    auto rd = std::make_shared<CSG2D::Rectangle>(100.f, 100.f, rotate(sf::Vector2f(0.f, -50.f), -std::numbers::pi/6.f), -std::numbers::pi/6.f);
    auto od = std::make_shared<CSG2D::ComplexShape>(letter_o, rd, CSG2D::OPERATION::INTERSECTION);

    auto letter_c = std::make_shared<CSG2D::ComplexShape>(ou, od, CSG2D::OPERATION::UNION);

    return letter_c;
}

std::shared_ptr<CSG2D::Shape> createCSG2DScene()
{
    // C
    auto circle_shp = std::make_shared<CSG2D::Circle>(300.f, sf::Vector2f(00.f, 100.f));
    auto inside_circle_shp = std::make_shared<CSG2D::Circle>(200.f, sf::Vector2f(00.f, 100.f));
    auto shp_C = std::make_shared<CSG2D::ComplexShape>(circle_shp, inside_circle_shp, CSG2D::OPERATION::DIFFERENCE);
    auto rect1_shp =  std::make_shared<CSG2D::Rectangle>(150.f, 100.f, sf::Vector2f(250.f, 150.f), std::numbers::pi / 6.f);
    auto rect2_shp =  std::make_shared<CSG2D::Rectangle>(150.f, 100.f, sf::Vector2f(250.f, 0.f), (-1*std::numbers::pi / 6.f));
    auto rect4_shp = std::make_shared<CSG2D::ComplexShape>(rect1_shp, rect2_shp, CSG2D::OPERATION::UNION);
    auto rect3_shp =  std::make_shared<CSG2D::Rectangle>(150.f, 100.f, sf::Vector2f(250.f, 75.f), 0);
    auto rect_diff_shp = std::make_shared<CSG2D::ComplexShape>(rect4_shp, rect3_shp, CSG2D::OPERATION::UNION);

    auto full_C_shp = std::make_shared<CSG2D::ComplexShape>(shp_C, rect_diff_shp, CSG2D::OPERATION::DIFFERENCE);
    //return full_C_shp;

//    auto rect1_shp =  std::make_shared<CSG2D::Rectangle>(150.f, 100.f, sf::Vector2f(250.f, 150.f), std::numbers::pi / 6.f);
//    auto rect2_shp =  std::make_shared<CSG2D::Rectangle>(150.f, 100.f, sf::Vector2f(250.f, 0.f), (-1*std::numbers::pi / 6.f));
//    auto rect4_shp = std::make_shared<CSG2D::ComplexShape>(rect1_shp, rect2_shp, CSG2D::OPERATION::UNION);
//    auto rect3_shp =  std::make_shared<CSG2D::Rectangle>(150.f, 100.f, sf::Vector2f(250.f, 75.f), 0);
//    auto rect_diff_shp std::make_shared<CSG2D::ComplexShape>(rect4_shp, rect3_shp, CSG2D::OPERATION::UNION);


    //dwa plusy
    auto cross_x_shp = std::make_shared<CSG2D::Rectangle>(150.f, 50.f, sf::Vector2f(230.f, 80.f), 0);
    auto cross_y_shp = std::make_shared<CSG2D::Rectangle>(50.f, 150.f, sf::Vector2f(230.f, 80.f), 0);
    auto cross_x2_shp = std::make_shared<CSG2D::Rectangle>(150.f, 50.f, sf::Vector2f(400.f, 80.f), 0);
    auto cross_y2_shp = std::make_shared<CSG2D::Rectangle>(50.f, 150.f, sf::Vector2f(400.f, 80.f), 0);
    auto cross_shp = std::make_shared<CSG2D::ComplexShape>(cross_x_shp, cross_y_shp, CSG2D::OPERATION::UNION);
    auto cross_shp2 = std::make_shared<CSG2D::ComplexShape>(cross_x2_shp, cross_y2_shp, CSG2D::OPERATION::UNION);
    auto full_cross_shp = std::make_shared<CSG2D::ComplexShape>(cross_shp, cross_shp2, CSG2D::OPERATION::UNION);

    auto full_Cpp_shp = std::make_shared<CSG2D::ComplexShape>(full_cross_shp, full_C_shp, CSG2D::OPERATION::UNION);
    //return full_Cpp_shp;

    // J
    auto name_cross_x_shp = std::make_shared<CSG2D::Rectangle>(150.f, 30.f, sf::Vector2f(220.f, -200.f), 0);
    auto name_cross_y_shp = std::make_shared<CSG2D::Rectangle>(30.f, 150.f, sf::Vector2f(280.f, -280.f), 0);
    auto name_cross_shp = std::make_shared<CSG2D::ComplexShape>(name_cross_x_shp, name_cross_y_shp, CSG2D::OPERATION::UNION);

    auto name_circle_out_shp = std::make_shared<CSG2D::Circle>(70.f, sf::Vector2f(226.f, -350.f));
    auto name_circle_in_shp = std::make_shared<CSG2D::Circle>(39.5f, sf::Vector2f(226.f, -350.f));
    auto name_circle2_shp = std::make_shared<CSG2D::ComplexShape>(name_circle_out_shp, name_circle_in_shp, CSG2D::OPERATION::DIFFERENCE);
    auto name_circle_rect_shape = std::make_shared<CSG2D::Rectangle>(150.f, 90.f, sf::Vector2f(220.f, -310.f), 0);
    auto name_circle_shp = std::make_shared<CSG2D::ComplexShape>(name_circle2_shp, name_circle_rect_shape, CSG2D::OPERATION::DIFFERENCE);

    auto full_j_shp = std::make_shared<CSG2D::ComplexShape>(name_cross_shp, name_circle_shp, CSG2D::OPERATION::UNION);
    // K
    auto name_rect1_shp =  std::make_shared<CSG2D::Rectangle>(130.f, 30.f, sf::Vector2f(400.f, -230.f), std::numbers::pi / 3.f);
    auto name_rect2_shp =  std::make_shared<CSG2D::Rectangle>(130.f, 30.f, sf::Vector2f(400.f, -335.f), -1*std::numbers::pi / 3.f);
    auto x_k_shp = std::make_shared<CSG2D::ComplexShape>(name_rect1_shp, name_rect2_shp, CSG2D::OPERATION::UNION);
    auto name_rect3_shp = std::make_shared<CSG2D::Rectangle>(200.f, 30.f, sf::Vector2f(360.f, -280.f), std::numbers::pi / 2.f);
    auto half_k_shp = std::make_shared<CSG2D::ComplexShape>(x_k_shp, name_rect3_shp, CSG2D::OPERATION::UNION);

    auto name_rect4_shp = std::make_shared<CSG2D::Rectangle>(200.f, 30.f, sf::Vector2f(360.f, -170.f), 0);
    auto name_rect5_shp = std::make_shared<CSG2D::Rectangle>(200.f, 30.f, sf::Vector2f(360.f, -390.f), 0);
    auto name_box_k_cut_shp = std::make_shared<CSG2D::ComplexShape>(name_rect5_shp, name_rect4_shp, CSG2D::OPERATION::UNION);

    auto full_k_shp = std::make_shared<CSG2D::ComplexShape>(half_k_shp, name_box_k_cut_shp, CSG2D::OPERATION::DIFFERENCE);

    auto full_jk_shp = std::make_shared<CSG2D::ComplexShape>(full_j_shp, full_k_shp, CSG2D::OPERATION::UNION);
    //return full_jk_shp;

    auto full_obj_shp = std::make_shared<CSG2D::ComplexShape>(full_jk_shp, full_Cpp_shp, CSG2D::OPERATION::UNION);
    return full_obj_shp;


//niżej są testy
    // auto rect_shp = std::make_shared<CSG2D::Rectangle>(160.f, 80.f, sf::Vector2f(-320.f, -120.f), std::numbers::pi / 4.f);
    // return rect_shp;

    // const auto op = CSG2D::OPERATION::UNION;
    // auto circle_shp = std::make_shared<CSG2D::Circle>(100.f, sf::Vector2f(-50.f, 0.f));
    // auto rect_shp = std::make_shared<CSG2D::Rectangle>(200.f, 200.f, sf::Vector2f(50.f, 0.f));
    // auto shp = std::make_shared<CSG2D::ComplexShape>(circle_shp, rect_shp, op);
    // return shp;

    // const auto op = CSG2D::OPERATION::UNION;
    // auto circle_shp = std::make_shared<CSG2D::Circle>(100.f, sf::Vector2f(-50.f, 0.f));
    // auto rect_shp = std::make_shared<CSG2D::Rectangle>(200.f, 200.f, sf::Vector2f(50.f, 0.f));
    // auto shp = std::make_shared<CSG2D::ComplexShape>(circle_shp, rect_shp, op, sf::Vector2f(200.f, 0.f), std::numbers::pi / 4.f);
    // return shp;

    // auto c_shp = createCSG2DCShape();
    // return c_shp;
}


//std::shared_ptr<CSG2D::Shape> createCSG2DScene()
//{
//	std::shared_ptr<CSG2D::Shape> shp;
//	//return shp;
////    auto circle_shp = std::make_shared<CSG2D::Circle>(10.f, Vector2D(0.f, 0.f));
////    return circle_shp;
//    auto rect_shp = std::make_shared<CSG2D::Rectangle>(16.f, 8.f, Vector2D(-32.f, -12.f),
////                                                       std::numbers::pi / 4.f);
//    return rect_shp;
//}
