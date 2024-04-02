# ��ǻ�ͱ׷��Ƚ��׿���ó�� ���� 1

- �� ������ ���� ȯ�����δ� vscode�� cmake�� ����Ͽ����ϴ�.
- �ʱ� ȯ�� ���� �� openGL�� �ٷ�� ���� �ʿ��� ��ų�� ��ũ�� ���󰡸� Ȯ���Ͻ� �� �ִ� [��Ʃ�� ���� ������](https://www.youtube.com/playlist?list=PLvNHCGtd4kh_cYLKMP_E-jwF3YKpDP4hf)�� �����Ͽ� �����Ͽ����ϴ�.
- �� �ܿ��� [LearnOpenGL.com](https://learnopengl.com) �� [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) ���� �����Ͽ���, ��ҿ� �п��� ������ �޾� �����Ͽ����ϴ�.

---

### ���� ����
- [ȯ�� ����](#ȯ��-����)

- [���� ���](#����-���)

- [��� ȭ��](#���-ȭ��)

- [Code ����](#code-����)

---

### ȯ�� ����

- vscode version 1.87�� ����Ͽ����ϴ�.
- cmake�� �ּ��� version 3.23�� ����ؾ� �մϴ�.
- �� repository�� �ִ� CMakeLists.txt�� Dependency.cmake ������ ���� �ʿ��� library�� �ʱ� ���� �� �� ���� �ٿ�ε� ���� �� �ֽ��ϴ�.

---

### ���� ���

1. vscode�� ���� ��, �ش� project�� �ִ� directory�� ���� project folder�� load���ݴϴ�.
2. CMake�� ���� vscode extension�� �ʿ��ϹǷ�, extension�� �������� �ʴ´ٸ� vscode ������ Extensions �ǿ��� cmake�� �˻��Ͽ� CMake�� CMake Tools�� install ���ݴϴ�.
3. Windows ȯ�濡���� ctrl + shift + p, Mac ȯ�濡���� cmd + p Ű�� �Է��Ͽ� command�� �Է��� �� �ִ� â���� cmake�� �˻� �� CMake:Configure�� �����ϰ�, �ü���� �°� �����Ϸ� ŰƮ�� �����մϴ�.

    (Ȥ�� �ش� ������Ʈ�� �ִ� �������� cmd â�� ���� code .�� �Է��ϸ� �ڵ����� CMake project���� �ν��ϰ� configure�� ���� �˾��� ��ϴ�.)

    Configure�� �����ϸ� vscode �ϴ��� OUTPUT �ǿ� "Configuring project: CGIP_hw1"�̶�� ��µǴ� ���� Ȯ���Ͻ� �� �ֽ��ϴ�.

4. CMake ������Ʈ�� �ν��� �Ǿ�����, �ٽ� command�� �Է��� �� �ִ� â�� ���� CMake�� �˻��Ͽ� CMake:Build�� �����մϴ� (Ȥ�� ����Ű�� F7�� �Է��մϴ�).

    �ʱ� build���, �̶� �ʿ��� library�� ���� build ������ �ٿ�ε� �˴ϴ�.

5. �ʱ� build�� ��ģ ��, ctrl + F5�� �Է��ϸ� Debug ���� project�� ����˴ϴ�.
Debug ����̹Ƿ� �ϴ��� DEBUG CONSOLE���� ��� �� ������ Ȯ���� �� �ֽ��ϴ�.

---

### ��� ȭ��

- Q1�� ���� ��� ȭ���� ������ �����ϴ�.
    - �� ���� ���� �ϳ��� ��鿡 ���Ͽ� �� ǥ�� ���� ray tracing ����� ������� ��Ÿ�� ȭ���Դϴ�.
<p align="center">
    <img src = "screenshot/Screenshot_Q1.png">
</p>
    

- Q2�� ���� ��� ȭ���� ������ �����ϴ�.
    - �� ���� ���� �ϳ��� ����� ������ �����ϰ�, Phong shading�� ���� ���� ���ȿ� ���� shading ȿ���� �����ϰ�, �׸��ڸ� �����Ͽ����ϴ�. ���� gamma correction�� �����Ͽ����ϴ�.
<p align="center">
    <img src = "screenshot/Screenshot_Q2.png">
</p>

- Q3�� ���� ��� ȭ���� ������ �����ϴ�.
    - Q2�� ������� �� pixel�� sampling�� 0���� 1������ float ���� �������� �����Ͽ�, �� �ȼ��� ���Ͽ� 64�� sampling�� �����Ͽ� anti-aliasing�� �����Ͽ����ϴ�.
    - �׸��� �κ��� ���ϸ� anti-aliasing�� ����� ���� Ȯ���ϰ� �巯���ϴ�.
<p align="center">
    <img src = "screenshot/Screenshot_Q3.png">
</p>

---

### Code ����

- ��� �ҽ��ڵ� ������ src ������ �ֽ��ϴ�.
    - Ray.h ������ Ray�� ��Ÿ���ϴ�. �ش� ����� Camera.h���� ȣ��Ǿ� ray tracing�� �⿩�մϴ�.
    - Camera.h ������ ī�޶�, �� ������ �����մϴ�.
    
        �� ��� ���Ͽ��� getRay�� getRandomRay �Լ��� �����Ͽ���, �̸� ���� ray tracing�� ���������ϴ�.
    - Light.h ������ ������ ��Ÿ���ϴ�.
    - Plane.h ������ ����� ��Ÿ���ϴ�.
    - Sphere.h ������ ���� ��Ÿ���ϴ�.
    - Scene.h ������ ��ü scene, �� ������ ���� ����� �׷��� ��Ÿ���ϴ�.

    - main.cpp ������ ������ �ٽ��� �Ǵ� �����Դϴ�.

        �Ʒ��� main.cpp ������ �� �Լ��� ���Ͽ� �����ϱ� ���� �����Դϴ�.

- array<int, 4> hitSurface(Ray ray, Scene scene) �Լ�
    
    �� �Լ��� ray�� object�� surface�� ���������� Ȯ���ϱ� ���� �Լ��Դϴ�.
    ������ �ڵ�� ������ �����ϴ�.

    ���� ���� ��ȯ���� �����ϱ� ���� ������ �����ϰ� �ʱⰪ�� �����մϴ�.
    ```
    array<int, 4> hit = {0, 0, 0, 0};
    ```
    ���� ���Ͽ� ����ϴ� ���, ���� �������� �����Ͽ� ������ t�� ���� ���� at^2 + bt + c = 0�̶�� �Ͽ��� ��, ���� ������ ���� ������ hit�ϴ��� �ƴ����� Ȯ���մϴ�.

    ���� ���� ���Ŀ��� sqrt ���ο� ���� �ϴ� �Ǻ����� 0���� �۴ٸ� hit���� �ʴ� ���̹Ƿ�, �̿� �°� ���� �����մϴ�.
    ```
    for(int i = 0; i < 3; i++) {
        Sphere sphere = scene.sphere[i];
        float a = dot(ray.direction, ray.direction);
        float b = 2 * dot(ray.direction, ray.origin - sphere.center);
        float c = dot(ray.origin - sphere.center, ray.origin - sphere.center) - (sphere.radius * sphere.radius);

        float discriminant1 = b * b - 4 * a * c;

        if(discriminant1 >= 0) {
            hit[i] = 1;
        } else {
            hit[i] = 0;
        }
    }
    ```
    ����� ��� normal vector�� ray direction�� �������� ������ hit�� ���̹Ƿ�, �̿� �°� ���� �����մϴ�.
    ```
    Plane plane = scene.plane;

    float discriminant2 = glm::dot(ray.direction, plane.normal);

    if(discriminant2 != 0) {
        hit[3] = 1;
    } else {
        hit[3] = 0;
    }
    ```
    ���������� hit�� �ߴ��� �� �ߴ����� ���� array�� ��ȯ�մϴ�.
    ```
    return hit;
    ```

- array<float, 4> calculateT(Ray ray, Scene scene) �Լ�
    
    �� �Լ��� ray�� origin���� direction�� ���� object�� �ε����� ���� �� ���� ����� ������ t0�� ���� ���ϱ� ���� �Լ��Դϴ�.
    ������ �ڵ�� ������ �����ϴ�.

    ���� ���� ��ȯ���� �����ϱ� ���� ������ �����ϰ� �ʱⰪ�� �����մϴ�.
    ```
    array<float, 4> t = {-1.0f, -1.0f, -1.0f, -1.0f};
    ```
    ���� ���������� ���� ���Ͽ� ����ϴ� ���, ���� �������� �����Ͽ� ������ t�� ���� ���� at^2 + bt + c = 0�̶�� �Ͽ��� ��, ���� ������ ���� ������ hit�� ���� t ���� ���մϴ�.
    ```
    for(int i = 0; i < 3; i++) {
        Sphere sphere = scene.sphere[i];
        float a = dot(ray.direction, ray.direction);
        float b = 2 * dot(ray.direction, ray.origin - sphere.center);
        float c = dot(ray.origin - sphere.center, ray.origin - sphere.center) - (sphere.radius * sphere.radius);

        float discriminant = b * b - 4 * a * c;

        t[i] = ((-1) * b - sqrt(discriminant)) / (2 * a);
    }
    ```
    ��鿡 ���Ͽ� ����ϴ� ���� ������ �����ϴ�.
    ```
    Plane plane = scene.plane;
    t[3] = dot(plane.normal, plane.point - ray.origin) / dot(plane.normal, ray.direction);
    ```
    ���������� �� object�� t0 ���� ������ array t�� ��ȯ�մϴ�.
    ```
    return t;
    ```

- vec3 evaluateRay(Ray ray, float t) �Լ�

    �� �Լ��� t ���� ����� ���� ���� ray�� �����ϴ� 3D ���� ���� ������ ����ϱ� ���� �Լ��Դϴ�.
    ������ �ڵ�� ������ �����ϴ�.
    ```
    return ray.origin + t * ray.direction;
    ```

- HitSurface intersect(Ray ray, Scene scene, float tMin, float tMax) �Լ�

    �� �Լ��� HitSurface ����ü�� ��ȯ�մϴ�. 

    HitSurface ����ü�� ������ ���� ����Ǿ� �ֽ��ϴ�.
    ```
    struct HitSurface {
        bool hit;
        float t;
        Color color;
        int firstSurface;
    };
    ```
    �� �Լ��� ���ο��� tMin�� tMax ������ tBest ���� ã��, tMax�� tBest ������ ��ȯ�Ͽ� ���ذ��� ������ tBest�� ã���ϴ�.

    ���� ���� ��ȯ���� �����ϱ� ���� ������ �����ϰ� �ʱⰪ�� �����մϴ�.
    ```
    HitSurface hsf = {false, -1.0f};
    ```
    �ʱ��� tBest�� tMax�̸�, �ϳ��� hit�� ��� t ���� ����Ͽ� tValues��� array�� ����ֽ��ϴ�.
    ���� tValues array �ȿ� �ִ� t ���� tMin���� ũ�� ������ tBest���� �۴ٸ� t�� tBest�� �˴ϴ�.
    �׸��� tBest�� ������ hsf�� firstSurface�� �����մϴ�.
    ```
    float tBest = tMax;

    if (hitSurface(ray, scene)[0] != 0 || hitSurface(ray, scene)[1] != 0 || hitSurface(ray, scene)[2] != 0 || hitSurface(ray, scene)[3] != 0) {
        array<float, 4> tValues = calculateT(ray, scene);
        for (int i = 0; i < 4; i++) {
            float t = tValues[i];
            if (t > tMin && t < tBest) {
                tBest = t;
                hsf.hit = true;
                hsf.t = tBest;

                hsf.firstSurface = i;
            }
        }
    }
    ```
    ���������� hsf�� ��ȯ�մϴ�.
    ```
    return hsf;
    ```

- vec3 calculateShading(Ray ray, Scene scene, HitSurface hsf, Light light) �Լ�

    �� �Լ��� shading�� shadow�� ����Ͽ� �� object�� �� pixel�� ���� �����ϱ� ���� �Լ��Դϴ�.

    ���� ���� ��ȯ���� �����ϱ� ���� ������ ������ �����ϱ� ���� ����, �׸��� ��꿡 �ʿ��� �������� �����ϰ�, ���� �����մϴ�.
    ```
    vec3 shading = vec3(1, 1, 1);

    array<float, 4> I;
    array<glm::vec3, 4> kd, ks, ka, n, l, h, v, point;
    array<Color, 4> Ia;
    array<int, 4> specular;

    int i = hsf.firstSurface;
    if (i == 3) {
        kd[i] = scene.plane.kd;
        ks[i] = scene.plane.ks;
        ka[i] = scene.plane.ka;
        I[i] = light.intensity;
        point[i] = evaluateRay(ray, hsf.t);
        v[i] = normalize(-ray.direction);
        n[i] = scene.plane.normal;
        l[i] = normalize(light.position - point[i]);
        h[i] = normalize(v[i] + l[i]);
        Ia[i].r = light.color.r;
        Ia[i].g = light.color.g;
        Ia[i].b = light.color.b;
        specular[i] = scene.plane.specular;
    } else {
        kd[i] = scene.sphere[i].kd;
        ks[i] = scene.sphere[i].ks;
        ka[i] = scene.sphere[i].ka;
        I[i] = light.intensity;
        point[i] = evaluateRay(ray, hsf.t);
        v[i] = normalize(-ray.direction);
        n[i] = normalize(point[i] - scene.sphere[i].center);
        l[i] = normalize(light.position - point[i]);
        h[i] = normalize(v[i] + l[i]);
        Ia[i].r = light.color.r;
        Ia[i].g = light.color.g;
        Ia[i].b = light.color.b;
        specular[i] = scene.sphere[i].specular;
    }
    ```
    Shadow�� �����ϱ� ���� ������ �����մϴ�.
    ```
    Ray shadowRay = {point[i], l[i]};
    HitSurface hsfShadow = intersect(shadowRay, scene, 0.0f, INFINITY);
    ```
    shadowRay�� �����ٸ� ambient shading���� ����ǰ�, �̿��� ��쿡�� ���� Phong shading�� ����ȼ�ϴ�.
    ```
    if(hsfShadow.hit) {
        shading.r = ka[i].r * Ia[i].r;
        shading.g = ka[i].g * Ia[i].g;
        shading.b = ka[i].b * Ia[i].b;
    } else {
        shading.r = ka[i].r * Ia[i].r + kd[i].r * I[i] * std::max(0.0f, dot(n[i], l[i])) + ks[i].r * I[i] * pow(std::max(0.0f, dot(n[i], h[i])), specular[i]);
        shading.g = ka[i].g * Ia[i].g + kd[i].g * I[i] * std::max(0.0f, dot(n[i], l[i])) + ks[i].g * I[i] * pow(std::max(0.0f, dot(n[i], h[i])), specular[i]);
        shading.b = ka[i].b * Ia[i].b + kd[i].b * I[i] * std::max(0.0f, dot(n[i], l[i])) + ks[i].b * I[i] * pow(std::max(0.0f, dot(n[i], h[i])), specular[i]);
    }
    ```
    ���������� ������ ������ shading�� ��ȯ�մϴ�.
    ```
    return shading;
    ```

- float gammaCorrect(float value, float gamma) �Լ�

    �� �Լ��� gamma correction�� ���� �Լ���, gamma correction�� �ϱ� ���� ���� �����մϴ�.
    ```
    float gammaCorrect(float value, float gamma) {
        return pow(value, 1.0f / gamma);
    }
    ```

- int main() �Լ�
    �� �Լ��� â�� ���� ���� �κа� pixel�� ä�� �̹����� �����ϱ� ���� �κ����� �����Ǿ� �ֽ��ϴ�.

    �߿��� �κ��� pixel�� ä�� �̹����� �����ϴ� �κ��̹Ƿ�, �ش� �ڵ常�� �Ʒ����� �ٷ�ڽ��ϴ�.

    ī�޶�� object(3 ���� ���� �ϳ��� ���)�� �����ϰ�, ������ �� object�� scene�� ���� �ֽ��ϴ�.

    ������ ���� ���뵵 �߰��ϰ�, gamma correction�� ���� gamma �� ���� �����մϴ�.
    ```
    Camera camera;

    Sphere S1 = {vec3(-4, 0, -7), 1, {1, 0, 0}, vec3(0.2, 0, 0), vec3(1, 0, 0), vec3(0, 0, 0), 0};
    Sphere S2 = {vec3(0, 0, -7), 2, {0, 1, 0}, vec3(0, 0.2, 0), vec3(0, 0.5, 0), vec3(0.5, 0.5, 0.5), 32};
    Sphere S3 = {vec3(4, 0, -7), 1, {0, 0, 1}, vec3(0, 0, 0.2), vec3(0, 0, 1), vec3(0, 0, 0), 0};

    Plane P = {vec3(0, 1, 0), vec3(0, -2, 0), {1, 1, 1}, vec3(0.2, 0.2, 0.2), vec3(1, 1, 1), vec3(0, 0, 0), 0};

    Scene scene = {S1, S2, S3, P};

    Light light = {vec3(-4, 4, -3), {1, 1, 1}, 1.0f};

    float gamma = 2.2f;
    ```
    �� pixel�� ���Ͽ� random ray�� �����ϰ�, �� random ray�� object�� ǥ���� hit�ϴ��� �ƴ����� sampleNum��ŭ Ȯ���մϴ�.

    hit�ϴ� ��� ���� finalColor ������ ������ shading ����� ��� ���մϴ�.

    Normalization�� ���Ͽ� hit�� pixel�� ���ؼ��� sampleNum��ŭ���� ������, 1���� ū ���� �������� �ʵ��� �մϴ�.

    ���� gamma correction�� ��ġ�� ���������� 255��ŭ ���ϸ� hit�� pixel�� ���� RGB ���� ������ �� �ֽ��ϴ�.

    hit���� ���� �κ��� RGB ���� ��� 0���� �Ӵϴ�.
    ```
    for(int iy = 0; iy < Ny; iy++) {
        for(int ix = 0; ix < Nx; ix++) {
            int idx = (iy * Ny + ix) * 3;
            Ray ray;
            HitSurface hsf;
            Color finalColor = {0, 0, 0};
            
            for (int sample = 0; sample < sampleNum; sample++) {
                ray = camera.getRandomRay(ix, iy);

                hsf = intersect(ray, scene, 0.0f, INFINITY);

                if(hsf.hit) {
                    finalColor.r += calculateShading(ray, scene, hsf, light).r;
                    finalColor.g += calculateShading(ray, scene, hsf, light).g;
                    finalColor.b += calculateShading(ray, scene, hsf, light).b;
                    
                }
            }

            if(hsf.hit) {
                finalColor.r /= float(sampleNum);
                finalColor.g /= float(sampleNum);
                finalColor.b /= float(sampleNum);

                // have to be normalized before gamma correction
                finalColor.r = (finalColor.r) > 1 ? 1 : finalColor.r;
                finalColor.g = (finalColor.g) > 1 ? 1 : finalColor.g;
                finalColor.b = (finalColor.b) > 1 ? 1 : finalColor.b;

                finalColor.r = gammaCorrect(finalColor.r, gamma);
                finalColor.g = gammaCorrect(finalColor.g, gamma);
                finalColor.b = gammaCorrect(finalColor.b, gamma);

                image[idx] = 255 * (finalColor.r);
                image[idx + 1] = 255 * (finalColor.g);
                image[idx + 2] = 255 * (finalColor.b);
            } else {
                image[idx] = 0;
                image[idx + 1] = 0;
                image[idx + 2] = 0;
            }
        }
    }
    ```
---

## �����մϴ�.

##### ������: �Ǳ����б� ���п� ��ǻ�Ͱ��а� 202371451 ������