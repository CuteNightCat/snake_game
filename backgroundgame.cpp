#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // 1. Tạo cửa sổ game
    sf::RenderWindow window(sf::VideoMode(900, 700), "SFML Game Background");
    
    // Đặt tốc độ khung hình giới hạn
    window.setFramerateLimit(60); 

    // --- Khởi tạo Background ---
    
    // 2. Tạo một đối tượng Texture (để lưu dữ liệu hình ảnh từ file)
    sf::Texture backgroundTexture;
    
    // 3. Load hình ảnh từ file vào Texture
    // Đảm bảo bạn có file 'background.png' trong thư mục dự án của mình!
    if (!backgroundTexture.loadFromFile("background.png"))
    {
        // Xử lý lỗi nếu không load được file
        std::cerr << "Lỗi: Không thể load background.png" << std::endl;
        return EXIT_FAILURE; 
    }
    
    // 4. Tạo một đối tượng Sprite (để hiển thị Texture lên màn hình)
    sf::Sprite backgroundSprite;
    
    // 5. Gán Texture cho Sprite
    backgroundSprite.setTexture(backgroundTexture);
    
    // Tùy chọn: Thay đổi kích thước Sprite để khớp với kích thước cửa sổ
    // Lấy kích thước hiện tại của texture
    sf::Vector2u texSize = backgroundTexture.getSize();
    
    // Tính toán tỷ lệ cần thiết (nếu bạn muốn background lấp đầy cửa sổ)
    float scaleX = (float)window.getSize().x / texSize.x;
    float scaleY = (float)window.getSize().y / texSize.y;
    
    backgroundSprite.setScale(scaleX, scaleY);

    // --- Vòng lặp Game chính ---
    while (window.isOpen())
    {
        window.display(); 
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // --- 1. Xóa màn hình ---
        window.clear(); 

        // --- 2. Vẽ các thành phần ---
        
        // **Vẽ Background trước**
        window.draw(backgroundSprite); 

        // Sau đó vẽ các đối tượng game khác (nhân vật, kẻ thù...) lên trên...
        // Ví dụ: window.draw(playerSprite);

        // --- 3. Hiển thị những gì đã vẽ lên cửa sổ ---
        window.display(); 
    }

    return EXIT_SUCCESS;
}