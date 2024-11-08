from PIL import Image, ImageDraw, ImageFont
import pandas as pd
import os

# Load the Excel data
excel_path = r'C:\Users\HP\Downloads\data.xlsx'  # Adjust path if needed
data = pd.read_excel(excel_path, header=0, dtype=str)
data.columns = data.columns.str.strip()

# Load the template image
template_path = r'C:\Users\HP\Downloads\Group8.jpg'  # Adjust path if needed
output_folder = r'C:\Users\HP\OneDrive\Desktop\OUTPUT\\'
a4_output_folder = r'C:\Users\HP\OneDrive\Desktop\OUTPUT\A4_Pages\\'

os.makedirs(output_folder, exist_ok=True)
os.makedirs(a4_output_folder, exist_ok=True)

# Define positions for each field in the image
positions = {
    'vidhalay': (165, 132),
    'jila': (163, 100),
    'srno': (20, 40),
    'Subject': (152, 167),
    'count': (250, 167),
    'class': (56, 167)
}

# Define font (adjust font path and size as per your system)
font_path = r'C:\Users\HP\Downloads\Noto_Sans_Devanagari\NotoSansDevanagari-VariableFont_wdth,wght.ttf'
font_size = 18
font = ImageFont.truetype(font_path, font_size)

# Set dimensions and padding for better fit on A4
single_image_width = 1200
single_image_height = 850
padding = 30  # Adjust padding as needed
a4_width, a4_height = 2480, 3508  # A4 in pixels at 300 DPI

# Generate individual images from the data
images = []
for index, row in data.iterrows():
    img = Image.open(template_path)
    draw = ImageDraw.Draw(img)

    # Write text to each field
    draw.text(positions['vidhalay'], str(row['vidhalay']), fill='red', font=font)
    draw.text(positions['jila'], str(row['jila']), fill='red', font=font)
    draw.text(positions['srno'], str(row['srno']), fill='red', font=font)
    draw.text(positions['Subject'], str(row['v1']), fill='red', font=font)
    draw.text(positions['count'], str(row['count1']), fill='red', font=font)
    draw.text(positions['class'], str(row['class1']), fill='red', font=font)

    # Save the generated image
    output_path = f"{output_folder}card_{index + 1}.jpg"
    img.save(output_path)
    images.append(img)
    print(f"Saved: {output_path}")

# Set the grid layout for each A4 page
images_per_page = 8
rows = 2
cols = 4
pages = [images[i:i + images_per_page] for i in range(0, len(images), images_per_page)]

# Arrange images onto A4 pages with padding
for page_index, page_images in enumerate(pages):
    a4_img = Image.new("RGB", (a4_width, a4_height), "white")

    # Paste images in a 4x2 grid with adjusted size and padding
    for i, img in enumerate(page_images):
        img_resized = img.resize((single_image_width, single_image_height))

        # Calculate offsets to arrange in a grid with padding
        x_offset = (i % 2) * (single_image_width + padding) + padding
        y_offset = (i // 2) * (single_image_height + padding) + padding
        a4_img.paste(img_resized, (x_offset, y_offset))

    # Save each A4-sized page
    a4_output_path = f"{a4_output_folder}A4_page_{page_index + 1}.jpg"
    a4_img.save(a4_output_path)
    print(f"Saved A4 page: {a4_output_path}")

print("All A4 pages generated with padding successfully.")
