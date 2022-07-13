def compute_distance(ball_1, ball_2):

    import math

    #e.g., ball_1 = (1, 2, 1)

    s = (ball_1[0] - ball_2[0]) * (ball_1[0] - ball_2[0])
    a = (ball_1[1] - ball_2[1]) * (ball_1[1] - ball_2[1])
    n = math.sqrt(s + a)

    return n

def detect_collision(ball_1, ball_2):
    if compute_distance(ball_1, ball_2) <= ball_1[2] + ball_2[2]:
        return True

    return False
    
